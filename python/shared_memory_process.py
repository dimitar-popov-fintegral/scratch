import os
import sys
import numpy

from multiprocess import Pool, RawArray
from typing import Tuple

var_dict = dict()

##################################################
def init_worker(x: RawArray, x_shape: Tuple):
    var_dict["x"] = x
    var_dict["x_shape"] = x_shape


##################################################
def worker(worker: int):
    print("This is worker [{}]".format(worker))
    wrapped_x = numpy.frombuffer(var_dict["x"]).reshape(var_dict["x_shape"])
    return numpy.einsum('...jk,...jq->...jq', wrapped_x, wrapped_x)


##################################################
def main() -> int:
    """Main function to test the use of memory sharing processes in python"""
    n=100; s=100; t=500
    tensor_dim = (n,t,s)
    tensor = numpy.random.standard_normal(tensor_dim)
    print("Size of arr [{}]".format(sys.getsizeof(tensor)))

    raw_x = RawArray('d', n*s*t)
    wrapped_x = numpy.frombuffer(raw_x).reshape(tensor_dim)
    numpy.copyto(wrapped_x, tensor)

    with Pool(processes=4, initializer=init_worker, initargs=(raw_x, tensor_dim)) as pool:
        res = pool.map(worker, range(n))
        print(res)

    return 0

##################################################
if __name__ == "__main__":
    assert main() == 0

