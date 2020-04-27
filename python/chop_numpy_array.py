import numpy
import time


##################################################
def chop(array, size_constraint=500):
    start = time.time()
    arr_shape = array.shape
    arr_order = len(arr_shape)
    arr_shape_arr = numpy.array(arr_shape)
    assert arr_order > 0

    print("got array of shape: ", arr_shape)

    if arr_order == 1:
        return 0, array.nbytes
    
    item_bytes = array.itemsize

    result = dict()
    max_size = 0.0
    max_dim = 0
    for dim in range(arr_order):
        slice_bytes = numpy.prod(numpy.delete(arr_shape_arr, dim)) * item_bytes / (1024**2)
        if slice_bytes > size_constraint:
            continue
        else:
            if slice_bytes > max_size:
                max_size = slice_bytes
                max_dim = dim

    assert max_size > 0
    print("that took [%s]s" %(time.time() - start))
    return max_dim, max_size


##################################################
if __name__ == "__main__":
    arr = numpy.ones((100, 60, 15, 250, 12)).astype(numpy.float)
    print("chop at dimension [%i] with size [%f]" %chop(arr))

