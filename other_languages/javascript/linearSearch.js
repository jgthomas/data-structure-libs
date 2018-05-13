const int_array = [1, 3, 5, 8, 12, 90, 33, 1, 5, 76, 32];
const args = process.argv.slice(2);

function linearSearch (sequence, target) {
    console.log("Linear Search");
    for (let i = 0; i < sequence.length; i++) {
        console.log(`Checking position ${i}`);
        if (sequence[i] === target) {
            console.log(`${target} found at position ${i}`);
            return;
        };
    };
    console.log(`${target} not found at any position`);
}

linearSearch(int_array, parseInt(args[0]));
