import os
import sys
import numpy
import time

from flask import Flask
from multiprocess import Pool, RawArray
from typing import Tuple

var_dict = dict()

##################################################
def init_worker(x: RawArray, x_shape: Tuple):
    var_dict["x"] = x
    var_dict["x_shape"] = x_shape


##################################################
def blueprint_worker(x: RawArray, x_shape: Tuple):
    """function to be used in flask worker/app"""
    wrapped_x = numpy.frombuffer(x).reshape(x_shape)
    n = x_shape[0]
    rand = numpy.random.RandomState(int(time.process_time() * 10e6) % 100)
    choice = rand.choice(numpy.array(range(n)), n//10)
    cov = numpy.einsum('...jk,...jq->...jq',
                       wrapped_x[choice,:,:],
                       wrapped_x[choice,:,:])

    return numpy.einsum('ijk,ijk', cov, cov)


##################################################
def worker(worker: int):
    print("This is worker [{}]".format(worker))
    wrapped_x = numpy.frombuffer(var_dict["x"]).reshape(var_dict["x_shape"])
    n = var_dict["x_shape"][0]
    rand = numpy.random.RandomState(int(time.process_time() * 10e6) % 100)
    choice = rand.choice(numpy.array(range(n)), n//10)
    return numpy.einsum('...jk,...jq->...jq',
                        wrapped_x[choice,:,:],
                        wrapped_x[choice,:,:])


##################################################
def create_app(test_config=None):
    """create the app for servicing requests for tensor ops"""
    n=100; s=1000; t=500
    tensor_dim = (n,t,s)
    tensor = numpy.random.standard_normal(tensor_dim)
    print("Size of arr [{}]".format(sys.getsizeof(tensor)))

    raw_x = RawArray('d', n*s*t)
    wrapped_x = numpy.frombuffer(raw_x).reshape(tensor_dim)
    numpy.copyto(wrapped_x, tensor)

    app = Flask(__name__, instance_relative_config=False)
    app.config["x"] = raw_x
    app.config["x_shape"] = tensor_dim

    return app
