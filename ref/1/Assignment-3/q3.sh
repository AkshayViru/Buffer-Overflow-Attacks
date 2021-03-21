count=0
while true; do
	printf 'count = %d\n' "$count"
	count=$((count+1))
	./bin3 dummy1.pgn
	if [ $? -eq 0 ];
	then
	break
	fi
done
