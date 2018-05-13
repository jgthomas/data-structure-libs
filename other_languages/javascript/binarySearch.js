const sorted_array = [1, 2, 3, 5, 6, 7, 8, 9, 12, 14, 17, 19, 34, 56, 77, 89, 100];
const args = process.argv.slice(2);

function binarySearch (sequence, target) {
    let low = 0;
    let high = sequence.length - 1;
    while (high >= low) {
        let mid = Math.floor((high + low) / 2)
        console.log(`Checking position ${mid}`);
        if (target < sequence[mid]) {
            high = mid - 1;
        } else if (target > sequence[mid]) {
            low = mid + 1;
        } else {
            console.log(`${target} found at position ${mid}`);
            return;
        };
    };
    console.log(`${target} not found at any position`);
}

binarySearch(sorted_array, parseInt(args[0]));
