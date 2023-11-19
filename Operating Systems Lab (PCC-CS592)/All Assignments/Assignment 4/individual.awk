#!/usr/bin/awk -f

BEGIN{
	if(ARGC!=2)
	{
		printf("Invalid Arguments\n");
		exit 1;
	}
	printf("File : %s\n",ARGV[1]);
	FS="~";
	printf("Awk Script started\n");
}
NR>1{
	if( ($3 > $4) && ($3 > $5))
	{
		printf("%s got the highest in SUB1. Marks : %d\n",$1,$3);
	}
	else if( ($4 > $3) && ($4 > $5))
	{
		printf("%s got the highest in SUB2. Marks : %d\n",$1,$4);
	}
	else
	{
		printf("%s got the highest in SUB3. Marks : %d\n",$1,$5);
	}
}
END{
	printf("Awk Script ended\n");
}
