function* calculator(intialValue) {
    const current = intialValue;
    while(true) {
        const input = yield current;
        if (
            !input ||
            typeof input.value !== "number" ||
            typeof input.operation !== "string"
        ) {
            yield "Invalid input";
            continue;
        }
        if(input.operation === "add") {
            current += input.value;
        }
        else if(input.operation === "subtract") {
            current -= input.value;
        }
        else if(input.operation === "multiply") {
            current *= input.value;
        }   
        else if(input.operation === "divide") {
            current /= input.value;
        } else {
            yield "Invalid operation";
            continue;
        }
    }
}