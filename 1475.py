number = input()
digits = [0] * 10

for digit in number:
    digit = int(digit)
    digits[digit] += 1

digits[6] = (digits[6] + digits[9] + 1) // 2
digits[9] = 0

max_count = max(digits)
print(max_count)
