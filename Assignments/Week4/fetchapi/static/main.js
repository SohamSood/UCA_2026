const worker = new Worker("worker.js");

worker.onmessage = function (event) {
    console.log(event.data);
};

worker.onerror = function (error) {
    console.error("Worker Error:", error.message);
};



