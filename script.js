// ===== DATA STORE =====
let expenses = [];

// ===== LOAD from localStorage on startup =====
window.addEventListener('DOMContentLoaded', () => {
    const saved = localStorage.getItem('student_expenses');
    if (saved) {
        try {
            expenses = JSON.parse(saved);
        } catch (e) {
            expenses = [];
        }
    }
    renderTable();
    renderBreakdown();
    updateSummary();
});

// ===== SAVE to localStorage =====
function saveData() {
    localStorage.setItem('student_expenses', JSON.stringify(expenses));
}

// ===== ADD EXPENSE =====
function addExpense() {
    const amountInput   = document.getElementById('amount');
    const categoryInput = document.getElementById('category');
    const noteInput     = document.getElementById('note');

    const amount   = parseFloat(amountInput.value);
    const category = categoryInput.value.trim();
    const note     = noteInput.value.trim();

    if (!amount || amount <= 0) {
        alert('Please enter a valid amount greater than 0.');
        amountInput.focus();
        return;
    }

    if (!category) {
        alert('Please select a category.');
        categoryInput.focus();
        return;
    }

    const expense = {
        id: Date.now(),
        amount: amount,
        category: category,
        note: note || '—'
    };

    expenses.push(expense);
    saveData();
    renderTable();
    renderBreakdown();
    updateSummary();

    // Reset form
    amountInput.value   = '';
    categoryInput.value = '';
    noteInput.value     = '';
    amountInput.focus();
}

// Allow Enter key to add expense from any form field
document.addEventListener('keydown', (e) => {
    if (e.key === 'Enter') {
        const active = document.activeElement;
        if (['amount', 'category', 'note'].includes(active.id)) {
            addExpense();
        }
    }
});

// ===== DELETE EXPENSE =====
function deleteExpense(id) {
    if (!confirm('Delete this expense?')) return;
    expenses = expenses.filter(e => e.id !== id);
    saveData();
    renderTable();
    renderBreakdown();
    updateSummary();
}

// ===== CLEAR ALL =====
function clearAll() {
    if (expenses.length === 0) {
        alert('No expenses to clear.');
        return;
    }
    if (!confirm('Are you sure you want to delete ALL expenses?')) return;
    expenses = [];
    saveData();
    renderTable();
    renderBreakdown();
    updateSummary();
}

// ===== FILTER EXPENSES =====
function getFiltered() {
    const search   = document.getElementById('searchInput').value.toLowerCase();
    const filterCat = document.getElementById('filterCategory').value;

    return expenses.filter(e => {
        const matchSearch = !search ||
            e.category.toLowerCase().includes(search) ||
            e.note.toLowerCase().includes(search);
        const matchCat = !filterCat || e.category === filterCat;
        return matchSearch && matchCat;
    });
}

// ===== RENDER TABLE =====
function renderTable() {
    const tbody    = document.getElementById('expenseBody');
    const filtered = getFiltered();

    tbody.innerHTML = '';

    if (filtered.length === 0) {
        tbody.innerHTML = `<tr><td colspan="5" class="empty-msg">No expenses found.</td></tr>`;
        return;
    }

    filtered.forEach((e, i) => {
        const tr = document.createElement('tr');
        tr.innerHTML = `
            <td>${i + 1}</td>
            <td><span class="badge badge-${e.category}">${e.category}</span></td>
            <td>₹${e.amount.toFixed(2)}</td>
            <td>${e.note}</td>
            <td><button class="delete-btn" onclick="deleteExpense(${e.id})">🗑 Delete</button></td>
        `;
        tbody.appendChild(tr);
    });
}

// ===== UPDATE SUMMARY CARDS =====
function updateSummary() {
    const total = expenses.reduce((sum, e) => sum + e.amount, 0);
    document.getElementById('totalAmount').textContent  = `₹${total.toFixed(2)}`;
    document.getElementById('expenseCount').textContent = expenses.length;

    // Top category
    if (expenses.length === 0) {
        document.getElementById('topCategory').textContent = '—';
        return;
    }

    const catTotals = {};
    expenses.forEach(e => {
        catTotals[e.category] = (catTotals[e.category] || 0) + e.amount;
    });

    const top = Object.entries(catTotals).sort((a, b) => b[1] - a[1])[0];
    document.getElementById('topCategory').textContent = top ? top[0] : '—';
}

// ===== RENDER CATEGORY BREAKDOWN =====
function renderBreakdown() {
    const container = document.getElementById('breakdown');

    if (expenses.length === 0) {
        container.innerHTML = `<p class="breakdown-empty">Add expenses to see category breakdown.</p>`;
        return;
    }

    // Group by category
    const catTotals = {};
    expenses.forEach(e => {
        catTotals[e.category] = (catTotals[e.category] || 0) + e.amount;
    });

    const total = expenses.reduce((sum, e) => sum + e.amount, 0);
    const sorted = Object.entries(catTotals).sort((a, b) => b[1] - a[1]);

    container.innerHTML = sorted.map(([cat, amt]) => {
        const pct = total > 0 ? (amt / total) * 100 : 0;
        return `
            <div class="breakdown-row">
                <span class="breakdown-label">${cat}</span>
                <div class="breakdown-bar-wrap">
                    <div class="breakdown-bar" style="width: ${pct.toFixed(1)}%"></div>
                </div>
                <span class="breakdown-amount">₹${amt.toFixed(2)}</span>
            </div>
        `;
    }).join('');
}

// ===== EXPORT CSV =====
function exportCSV() {
    if (expenses.length === 0) {
        alert('No expenses to export.');
        return;
    }

    const header = ['#', 'Category', 'Amount (INR)', 'Note'];
    const rows = expenses.map((e, i) =>
        [i + 1, e.category, e.amount.toFixed(2), `"${e.note.replace(/"/g, '""')}"`]
    );

    const total = expenses.reduce((sum, e) => sum + e.amount, 0);
    rows.push(['', 'TOTAL', total.toFixed(2), '']);

    const csv = [header, ...rows].map(r => r.join(',')).join('\n');
    const blob = new Blob([csv], { type: 'text/csv' });
    const url  = URL.createObjectURL(blob);

    const a    = document.createElement('a');
    a.href     = url;
    a.download = 'expenses.csv';
    a.click();

    URL.revokeObjectURL(url);
}