

const int_array = [1, 3, 5, 8, 12, 90, 33, 1, 5, 76, 32];


function countingSort (array) {
    const max = Math.max(...array) + 1;
    let counter = new Array(max).fill(0);
    let sorted_array = [];

    for (let i = 0; i < array.length; i++) {
        counter[array[i]]++;
    }

    for (let i = 0; i < max; i++) {
        while (counter[i] > 0) {
            sorted_array.push(i);
            counter[i]--;
        }
    }

    return sorted_array;
}

console.log(int_array);
const answer = countingSort(int_array);
console.log(answer);
