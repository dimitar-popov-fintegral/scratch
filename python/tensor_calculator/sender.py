import requests
import time 

from multiprocess import Pool

ENDPOINT_URL = "http://127.0.0.1:5000/calculator/compute_cov"


##################################################
def sender(i):
    print("sender [%i]" %i)
    resp = requests.get(ENDPOINT_URL)
    print(resp.text)
    time.sleep(1)

##################################################
def main() -> int:

    num_requests = 1000
    with Pool(processes=2) as pool:
        res = pool.map(sender, range(num_requests))

    return 0


##################################################
if __name__ == "__main__":
    assert main() == 0
