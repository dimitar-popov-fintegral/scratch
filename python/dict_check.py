def check(a, b):
    print("level [%s] \n" %",".join(a.keys()))
    for k,v in a.items():
        if isinstance(v, dict):
            check(a[k],b[k])
        assert k in b,\
            "key [%s] missing in b" %k
        assert v == b[k],\
            "mis-match in [%s], [%s] != [%s]" %(k, v, b[k])


if __name__ == "__main__":
    a = {
        "this": {
            "a": {
                "a": 1,
                "v": 2,
            },
            "b": 2,
        },
        "that": [
            1,
            2,
            3,
        ],
        "other": "clear",
    }


    b = {
        "this": {
            "a": {
                "a": 1,
                "v": 2,
            },
            "b": 2,
        },
        "that": [
            1,
            2,
            3,
        ],
        "other": "clear",
    }

    check(a, b)
    
