start=$(date +"%T"); \
echo "Starting time : $start"; \
for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
do
	now=$(date +"%T"); \
	echo "Run" $i "started at" $now; \
	./GEGCC pop 10 gen 250 seed 0 sloth 0.5 >> log/$i.log; \ 
	cp log/output_data.log runs/output$i.log; \
	cp log/edit_distance runs/edit_distance$i;
done
end=$(date +"%T"); \
echo "Ending time : $end"; \
