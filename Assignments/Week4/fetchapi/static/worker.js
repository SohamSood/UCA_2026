fetch("https://dummyapi.com/users")
    .then(response => {
        if (!response.ok) {
            throw new Error("Failed to fetch users");
        }
        return response.json();
    })
    .then(data => {
        if (!data || data.length === 0) {
            throw new Error("No users returned from API");
        }

        data.forEach(user => {
            const status = user.active ? "Active" : "Inactive";
            postMessage(`${user.name} - ${status}`);
        });
    })
    .catch(error => {
        postMessage("Error: " + error.message);
    });

