# Paiza learning
# プログラミングスキルチェック
# B004:ログファイルの抽出

directions = gets.chomp.split('.')
directions[0] = directions[0].to_i
directions[1] = directions[1].to_i
for i in 2..3
  if directions[i] == '*'
    directions[i] = [0, 255]
  elsif (matched = directions[i].match(/\[([0-9]+)-([0-9]+)\]/))
    directions[i] = [matched[1].to_i, matched[2].to_i];
  else
    directions[i] = [directions[i].to_i, directions[i].to_i]
  end
end

N = gets.to_i
N.times do |i|
  log = gets.chomp
  ip = log.match(/\A(.+) - - /)[1]
  ips = ip.split('.').map { |octet| octet.to_i }
  to_be_displayed = (ips[0] == directions[0])
  to_be_displayed &&= (ips[1] == directions[1])
  to_be_displayed &&= (directions[2][0] <= ips[2] && ips[2] <= directions[2][1])
  to_be_displayed &&= (directions[3][0] <= ips[3] && ips[3] <= directions[3][1])
  if to_be_displayed
    matched = log.match(/\[(.+) \+[0-9]+\] "(.+?)"/)
    time = matched[1]
    file = matched[2].split[1]
    puts ip + ' ' + time + ' ' + file
  end
end

