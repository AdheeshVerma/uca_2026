echo "Task One"
awk -F',' '{print $1, $2}' dataFile.txt
echo
echo "Task Two"
awk -F',' '$2=="Engineering" {print}' dataFile.txt
echo
echo "Task Three"
awk -F',' '{print $1, "gross pay: $" $3*$4}' dataFile.txt
echo
echo "Task Four"
awk -F',' '{print NR, "(" NF " fields):", $0}' dataFile.txt
echo
echo "Task Five"
awk -F',' '
BEGIN {
    total = 0
}
$2 == "Engineering" {
    total += $3 * $4
}
END {
    print "Total Engineering Payroll: $" total
}' dataFile.txt