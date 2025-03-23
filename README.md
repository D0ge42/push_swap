# Push_swap - 42 Project (125/100)

Push_swap is an **efficient sorting algorithm project** developed as part of the **42 School** curriculum. This implementation is based on the **Mechanical Turk variant**, achieving **highly optimized results** with an average of:
- **~5290 moves for 500 numbers**
- **~600 moves for 100 numbers**

With **full bonus implementation**, this project scored **125/100** in Moulinette evaluations. 🚀

---

## 🌟 Features
- **Efficient sorting algorithm** based on the Mechanical Turk approach
- **Handles any valid integer input within the `int` range**
- **Optimized for minimal operations**
- **Robust error handling & input validation**
- **Memory-leak free & stable performance**
- **Bonus implemented & fully validated**

---

## 🛠️ Compilation & Usage
### 🔧 Build
```bash
make
```

### 🚀 Run Push_swap
```bash
./push_swap "list of numbers"
```
Example:
```bash
./push_swap 4 67 3 87 23
```

### 🏆 Checking the Move Count
To check how many moves are used:
```bash
./push_swap 4 67 3 87 23 | wc -l
```

To validate sorting correctness:
```bash
./push_swap 4 67 3 87 23 | ./checker_linux 4 67 3 87 23
```
(Output should be `OK` if sorted correctly.)

---

## 📖 How It Works
1. **Parsing & Validation:** Checks for duplicates, non-numeric inputs, and integer overflow.
2. **Algorithm Execution:** Implements a **Mechanical Turk variant** to efficiently sort numbers.
3. **Move Optimization:** Ensures **minimal operations** are used to sort the list.
4. **Stack Manipulation:** Utilizes stacks `a` and `b` for sorting operations (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, etc.).

---

## 🏆 Why This Push_swap?
✅ **Optimized for performance** (5290 moves for 500 numbers, 600 for 100 numbers)  
✅ **Fully tested & verified** (125/100 Moulinette score)  
✅ **Handles all edge cases** (duplicates, overflows, invalid input)  
✅ **Memory-leak free & bulletproof implementation**  
✅ **Bonus features fully integrated**  

---

## 📜 License
This project is open-source and free to use for educational purposes.

---

Sorting made efficient with **Push_swap**! 🏆✨

