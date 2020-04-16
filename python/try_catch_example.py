

##################################################
def catch():
    data = ["1000", "100k", "no result", "100", "20K"]
    results = list()
    for obs in data:
        mult = 1
        if 'k' in obs or 'K' in obs:
            obs = obs.replace('k', '')
            obs = obs.replace('K', '')
            mult = 1000
        try:
            res = int(obs) * mult
            results.append(res)
        except Exception as e:
            print("hendled this error: ", e)
            pass
            
    print(results)


##################################################
if __name__ == "__main__":
    catch()
    print("done")
