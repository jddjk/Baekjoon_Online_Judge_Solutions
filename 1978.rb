def is_prime(n)
  return false if n < 2

  (2..Math.sqrt(n)).each do |i|
    return false if n % i == 0
  end

  return true
end

n = gets.to_i
numbers = gets.split.map(&:to_i)

prime_count = 0
numbers.each do |num|
  prime_count += 1 if is_prime(num)
end

puts prime_count
