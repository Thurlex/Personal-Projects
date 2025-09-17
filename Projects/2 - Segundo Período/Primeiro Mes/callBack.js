// Callback functions!
// When the function ends, another one is called

function process(callback) {
    console.log("Processing data...");

    callback(); // Executes the function that's received as an argument
};


let textProcessedData = _=> console.log("Data processed.");

process(textProcessedData);