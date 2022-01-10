start=$(date +"%T"); \
echo "Starting time : $start"; \
for i in 1 2 3 4 5
do
	now=$(date +"%T"); \
	echo "Run" $i "started at" $now; \
	./GEGCC pop 50 gen 100 seed 0 >> log/$i.log; \ 
	cp log/output_data.log runs/output$i.log;
	cp tmp/test_results runs/test_results$i.log;

done
end=$(date +"%T"); \
echo "Ending time : $end"; \
