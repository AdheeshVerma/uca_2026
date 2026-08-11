function* calculator(initialValue) {
    let result = initialValue;

    while (true) {
        const command = yield result;

        if (!command || !["add", "subtract", "multiply", "divide"].includes(command.operation) ||
            typeof command.value !== "number" ||
            Number.isNaN(command.value)
        ) {
            yield "Invalid input";
            continue;
        }

        if (command.operation === "divide" && command.value === 0) {
            yield "Invalid input";
            continue;
        }

        switch (command.operation) {
            case "add":
                result += command.value;
                break;

            case "subtract":
                result -= command.value;
                break;

            case "multiply":
                result *= command.value;
                break;

            case "divide":
                result /= command.value;
                break;

            default:
                console.log("Unknown operation");
        }
    }
}

const calc = calculator(50);

console.log(calc.next().value); // 50
console.log(calc.next({ operation: "add", value: 30 }).value); // 80
console.log(calc.next({ operation: "multiply", value: 2 }).value); // 160
console.log(calc.next({ operation: "add", value: "30" }).value); // Invalid input
console.log(calc.next({ operation: "multiply", value: 0 }).value); // 0