#!/usr/bin/awk -f

BEGIN{
	FS="~";
	printf("\nAwk Script Started..\n");
	highest=0;
}
NR>1{
	total=$3+$4+$5;
	if(total>highest)
	{
		highest=total;
		rec=$1;
	}
}
END{
	printf("Awk Script ended\n")
	printf("\n%s with %d has the highest total\n",rec,highest);
}
