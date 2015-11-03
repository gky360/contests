# Paiza learning
# プログラミングスキルチェック
# C008:文字列の抽出

tags = gets.split
str = gets
while !str.empty?
  matched = str.match(/#{tags[0]}(.*)/)
  if !matched
    exit
  end
  str = matched[1]
  matched = str.match(/(.*?)#{tags[1]}(.*)/)
  if !matched
    exit
  end
  puts matched[1].empty? ? '<blank>' : matched[1]
  str = matched[2]
end
