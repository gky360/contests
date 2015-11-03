# Paiza learning
# プログラミングスキルチェック
# C005:アドレス調査

N = gets.to_i
N.times do |i|
  addresses = gets.chomp.split('.')
  if addresses.count != 4
    puts 'False'
    next
  end
  valid = true
  addresses.each do |address|
    if address == ''
      valid = false
      break
    end
    if address.to_i > 255
      valid = false
      break
    end
  end

  puts valid ? 'True' : 'False'

end
