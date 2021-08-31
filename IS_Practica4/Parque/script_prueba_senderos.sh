
for i in $(seq 20); do
	touch "send$i.txt"
done

ls | egrep -o "send[1234567890]+" > senderos.txt
