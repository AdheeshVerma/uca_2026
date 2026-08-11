function* fibonacci() {
    let a = null;
    let b = null;

    while(true){
        if(a==null){
            a = 0;
            yield a;
        }
        if(b==null){
            b = 1;
            yield b;
        }

        let temp = b;
        b = b + a;
        a = temp;
        
        yield b;
    }
}

const fibGen = fibonacci();

console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);