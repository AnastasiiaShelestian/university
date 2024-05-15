import itertools

# Функция импликации (импликация P→Q эквивалентна ¬P∨Q)
def implies(p, q):
    return not p or q

# Функция главного выражения
def expression(p, q, r):
    # (P→Q)→(Q→R) эквивалентно implies(implies(p, q), implies(q, r))
    left = implies(implies(p, q), implies(q, r))
    # ¬R→¬P эквивалентно implies(not r, not p)
    right = implies(not r, not p)
    # ((P→Q)→(Q→R))→(¬R→¬P)
    result = implies(left, right)
    return result

# Генерация таблицы истинности
def truth_table():
    print("P  | Q  | R  | ((P→Q)→(Q→R))→(¬R→¬P)")
    print("-" * 37)
    # Генерация всех возможных комбинаций истинности для P, Q, R
    for p, q, r in itertools.product([True, False], repeat=3):
        # Вычисление результата функции для данных значений P, Q, R
        result = expression(p, q, r)
        # Вывод значений P, Q, R и результата
        print(f"{int(p)}  | {int(q)}  | {int(r)}  | {int(result)}")

# Генерация и вывод таблицы истинности
truth_table()
