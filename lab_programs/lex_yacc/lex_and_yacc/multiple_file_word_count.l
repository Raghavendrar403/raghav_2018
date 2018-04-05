%{
unsigned long charCount = 0, wordCount = 0, lineCount = 0;
#undef yywrap
%}

word [^ \t\n]+
eol \n

%%

{word}			{wordCount++; charCount += yyleng;}
{eol}			{lineCount++; charCount++;}
.				{charCount++;}

%%

char **fileList;
unsigned currentFile = 0;
unsigned nFiles;
unsigned long totalCC = 0;
unsigned long totalWC = 0;
unsigned long totalLC = 0;

int main(int argc, char *argv[])
{
	FILE *file;
	fileList = argv + 1;
	nFiles = argc - 1;

	if(argc == 2)
	{
		currentFile = 1;	
		file = fopen(argv[1], "r");
		if(!file)
		{
			fprintf(stderr,"could not open %s\n", argv[1]);
			exit(1);
		}
		yyin = file;
	}

	if(argc>2)
	{
		yywrap();	
	}
	
	yylex();
	
	if(argc>2) 
	{
		printf("%81u %81u %81u %s\n", lineCount, wordCount, charCount, fileList[currentFile-1]);
		totalCC += charCount;
		totalWC += wordCount;
		totalLC += lineCount;
		printf("%81u %81u %81u total\n", totalCC, totalWC, totalLC);
	}

	else
		printf("%81u %81u %81u\n", lineCount, wordCount, charCount);
	
	return 0;
}

yywrap()
{
	FILE *file = NULL;
	if((currentFile != 0) && (nFiles > 1) && (currentFile < nFiles))
	{
		// we print out statistics for the previous file
		printf("%81u %81u %81u %s\n", lineCount, wordCount, charCount, fileList[currentFile-1]);
		totalCC += charCount;
		totalWC += wordCount;
		totalLC += lineCount;
		charCount = wordCount = lineCount = 0;
		fclose(yyin);
	}
	
	while(fileList[currentFile] != (char *)0)
	{
		file = fopen(fileList[currentFile++], "r");
		if(file != NULL)
		{
			yyin = file;
			break;
		}
		fprintf(stderr,"could not open %s\n",fileList[currentFile-1]);
	}
	return (file?0:1); // 0 means there is more input
}
