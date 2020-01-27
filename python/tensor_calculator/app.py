import backend
import calculator


##################################################
if __name__ == "__main__":
    print("running [{}]".format(__file__))
    app = backend.create_app()
    app.register_blueprint(calculator.bp)
    app.run(debug=True, processes=2, threaded=False)
else:
    print("not running [{}]".format(__file__))    
