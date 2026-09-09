function CustomPromise(executorFunction) {
    let state = "PENDING";
    let value = null;

    let successCallbacks = [];
    let failureCallbacks = [];

    function resolve(result) {
        if (state !== "PENDING") {
            return;
        }

        state = "FULFILLED";
        value = result;

        // Execute all .then() callbacks
        successCallbacks.forEach(callback => {
            callback(value);
        });

        // Resetting callbacks
        successCallbacks = [];
        failureCallbacks = [];
    }

    function reject(error) {
        if (state !== "PENDING") {
            return;
        }
        state = "REJECTED";
        value = error;

        failureCallbacks.forEach(callback => {
            callback(value);
        });

        successCallbacks = [];
        failureCallbacks = [];
    }

    function then(func) {
        return new CustomPromise((resolve, reject) => {

            function successHandler(value) {
                try {
                    const result = func(value);
                    resolve(result);
                } catch (error) {
                    reject(error);
                }
            }

            if (state === "FULFILLED") {
                successHandler(value);
            }
            else if (state === "PENDING") {
                successCallbacks.push(successHandler);
            }
        });
    }

    function customCatch(func) {
        return new CustomPromise((resolve, reject) => {

            function faliureHandler(error) {
                try {
                    const result = func(error);
                    resolve(result);
                } catch (err) {
                    reject(err);
                }
            }

            if (state === "REJECTED") {
                faliureHandler(value);
            }
            else if (state === "PENDING") {
                failureCallbacks.push(faliureHandler);
            }
        });
    }

    try {
        executorFunction(resolve, reject);
    } catch (error) {
        reject(error);
    }

    return {
        then,
        catch: customCatch
    };
}