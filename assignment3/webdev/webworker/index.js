const worker  = new Worker("worker.js")
const url = "https://dummyjson.com/users"
async function getData() {
    try {
        const response = await fetch(url);

        if (!response.ok) {
            throw new Error("Failed to fetch users");
        }

        const data = await response.json();

        worker.postMessage(data.users || []);
    } catch (err) {
        console.error(err);
    }
}

getData();

worker.onmessage = (e) => {
    console.log(e.data);
};