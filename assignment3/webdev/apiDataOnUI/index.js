const url = "https://dummyjson.com/users";
const worker = new Worker("worker.js");
async function getUserData() {
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
const element = document.getElementById("users")

function displayData(data){
    if(data!==null && data.length>0){
        data.forEach(value => {
            const p = document.createElement('p');
            const name = value.name  || '';
            const gender = value.gender  || '';
            p.textContent = `${name}:${gender}`;
            element.appendChild(p);
        });
    }else{
        element.innerHTML = `No Users Found`
    }
}
getUserData();

worker.onmessage = (e) => {
   displayData(e.data);
};