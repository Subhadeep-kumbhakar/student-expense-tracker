let expenses = JSON.parse(localStorage.getItem("expenses")) || [];

    const total = expenses.reduce((sum, expense) => sum + expense.amount, 0);

    const warning = document.getElementById("budgetWarning");

    if (budget > 0 && total > budget) {

        warning.innerText = "⚠ Budget exceeded!";
    }

    else {

        warning.innerText = "";
    }
}

function renderExpenses() {

    const expenseList = document.getElementById("expenseList");

    const totalElement = document.getElementById("total");

    const search = document.getElementById("search").value.toLowerCase();

    expenseList.innerHTML = "";

    let total = 0;

    expenses.forEach((expense, index) => {

        if (
            expense.category.toLowerCase().includes(search) ||
            expense.note.toLowerCase().includes(search)
        ) {

            total += expense.amount;

            const card = document.createElement("div");

            card.className = "expense-card";

            card.innerHTML = `
                <div class="expense-info">
                    <h3>₹${expense.amount}</h3>
                    <p>Category: ${expense.category}</p>
                    <p>Note: ${expense.note}</p>
                </div>

                <div class="action-buttons">

                    <button class="edit-btn" onclick="editExpense(${index})">
                        Edit
                    </button>

                    <button class="delete-btn" onclick="deleteExpense(${index})">
                        Delete
                    </button>

                </div>
            `;

            expenseList.appendChild(card);
        }
    });

    totalElement.innerText = total;

    checkBudget();
}

renderExpenses();