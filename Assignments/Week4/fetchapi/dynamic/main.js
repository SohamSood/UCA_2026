const worker = new Worker("worker.js");

const usersDiv = document.getElementById("users");

worker.onmessage = function (event) {
    const users = event.data;

    usersDiv.innerHTML = "";

    users.forEach(user => {
        const p = document.createElement("p");
        p.textContent = `${user.name} - ${user.active ? "Active" : "Inactive"}`;
        usersDiv.appendChild(p);
    });
};

worker.onerror = function (error) {
    usersDiv.innerHTML = `<p>Error: ${error.message}</p>`;
};
