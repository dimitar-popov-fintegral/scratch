import numpy
import backend 
import time

from flask import Blueprint, current_app

bp = Blueprint('calculator', __name__, url_prefix='/calculator')
@bp.route('/compute_cov', methods=('GET',))
def compute_cov():
    raw_x = current_app.config["x"]
    raw_x_shape = current_app.config["x_shape"]
    res = backend.blueprint_worker(raw_x, raw_x_shape)

    return str(res)


