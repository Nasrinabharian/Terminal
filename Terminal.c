#include<stdio.h>
#pragma warning (disable:4996)
#include <iostream> 
#include <sys/stat.h> 
#include <sys/types.h>  
#include <process.h> 
#include <string.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <conio.h>
#include <stdlib.h>
#include<direct.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
void printFileProperties(struct stat stats);
struct rec
{
	int num;
	char name[40];
	char user[40];
	char pass[40];
	int power;
	int level;
	int wrong;
};
int main()
{
	char user[40], pa[40], order[100], cp[100], cc[100], p1[40] = { NULL }, add[200], str[200];
	int p, time, t[9] = { NULL }, b = 0, qq = 0;
	int MAX_TIME = 3600000;
	struct rec info[100];
	int i, n = 0, in[40];
	FILE *ptr;
	for (i = 1; i < 100; i++)
	{
		info[i].power = 0;
		info[i].level = 0;
		info[i].wrong = 0;
		cp[i] = NULL;
	}
	cp[0] = NULL;
	for (i = 1; i < 100; i++)
		for (int j = 0; j < 40; j++)
		{
			info[i].pass[j] = NULL;
			info[i].user[j] = NULL;
			info[i].name[j] = NULL;
		}
	info[0].level = 1;
	strcpy(info[0].name, "nasrin");
	strcpy(info[0].user, "admin\n");
	strcpy(info[0].pass, "(NASRIN,1379...)\n");
	info[0].num = 0;
	info[0].power = 84;
	info[0].level = 1;
	info[0].wrong = 0;
	mkdir("admin");
	chdir("admin");
	ptr = fopen("admin.txt", "w");
	fprintf(ptr, "%s %s %s %d %d %d", info[n].user, info[n].name, info[n].pass, info[n].level, info[n].power, info[n].wrong);
	fclose(ptr);
	DWORD Start, Duration = 0;
	Start = GetTickCount();
	while ((Duration < MAX_TIME))
	{
		if (!(Duration < MAX_TIME))
			break;
		printf("Enter your username:");
		fgets(user, 40, stdin);
		printf("Enter your password:");
		fgets(pa, 40, stdin);
		for (p = 0; p < 100; p++)
			S:if (strcmp(user, info[p].user) == 0 && strcmp(pa, info[p].pass) == 0)
		{
			b = 1;
		LOP:for (i = 0; i < 100; i++)
		{
			cc[i] = NULL;
			cp[i] = NULL;
			order[i] = NULL;
			if (i < 40)
				p1[i] = NULL;
		}
			printf("@%s", info[p].user);
			fgets(order, 50, stdin);
			int s = 0, d = 0;
			while (order[s] != ' ' && order[s] != '\0')
			{
				cp[s] = order[s];
				s++;
			}
			s++;
			if (strcmp(cp, "create") == 0 && info[p].level == 1)
			{
				n++;
				printf("Enter name:");
				fgets(info[n].name, 40, stdin);
				while (order[s] != '\n')
				{
					info[n].user[d] = order[s];
					d++;
					s++;
				}
			LOOP:printf("Enter password:");
				info[n].power = 0;
				fgets(info[n].pass, 40, stdin);
				for (i = 0; info[n].pass[i] != NULL; i++)
				{
					in[i] = info[n].pass[i] - '0';
					if ((info[n].pass[i]) >= 'a' && (info[n].pass[i]) <= 'z')
						info[n].power = info[n].power + 2;
					else if ((info[n].pass[i]) >= 'A' && (info[n].pass[i]) <= 'Z')
						info[n].power = info[n].power + 4;
					else if ((info[n].pass[i]) >= '0' && (info[n].pass[i]) <= '9')
						info[n].power = info[n].power + 3;
					else if (info[n].pass[i] == ' ')
						info[n].power = info[n].power + 1;
					else
						info[n].power = info[n].power + 8;
				}
				info[n].power = info[n].power - 8;
				if (info[n].power <= 33)
				{
					printf("your pass is weak.pleas enter another one:");
					Duration = GetTickCount() - Start;
					if ((Duration < MAX_TIME))
						goto LOOP;
					else
						break;
				}
				if (info[n].power >= 100)
				{
					info[n].power = 100;
				}
				char adr[200];
				getcwd(adr, 200);
				int w = qq;
				while (qq >= 0)
				{
					qq--;
					chdir("..");
				}
				mkdir(info[n].user);
				chdir(info[n].user);
				ptr = fopen(info[n].user, "w");
				fprintf(ptr, "%s %s %s %d %d %d", info[n].user, info[n].name, info[n].pass, info[n].level, info[n].power, info[n].wrong);
				fclose(ptr);
				chdir("..");
				qq = w;
				chdir(adr);
				printf("%s added\n", info[n].user);
				Duration = GetTickCount() - Start;
				if ((Duration < MAX_TIME))
					goto S;
				else
					break;
			}
			else if (strcmp(cp, "su") == 0)
			{
				if (info[p].level == 1)
					for (int e = 0; e <= n; e++)
					{
						while (order[s] != '\n')
						{
							cc[d] = order[s];
							d++;
							s++;
						}
						if (strcmp(cc, info[e].user) == 0)
						{
							p = e;
							strcpy(user, info[p].user);
							strcpy(pa, info[p].pass);
							DWORD Start, Duration = 0;
							Start = GetTickCount();
						}
					}
				else
				{
					while (order[s] != '\n')
					{
						cc[d] = order[s];
						d++;
						s++;
					}
					for (int e = 0; e <= n; e++)
					{
						if (e == 0)
							cc[d] = '\n';
						else
							cc[d] = '\0';
						if (strcmp(cc, info[e].user) == 0)
						{
							printf("Enter password.\n");
							fgets(p1, 40, stdin);
							if (strcmp(p1, info[e].pass) == 0)
							{
								p = e;
								strcpy(user, info[p].user);
								strcpy(pa, info[p].pass);
								for (int q = 0; q < 40; q++)
									p1[q] = NULL;
								DWORD Start, Duration = 0;
								Start = GetTickCount();
							}
							else
							{
								printf("you can't use this username.");
								Duration = GetTickCount() - Start;
								if ((Duration < MAX_TIME))
									goto S;
								else
									break;
							}
						}
					}

				}
				while (qq >= 0)
				{
					qq--;
					chdir("..");
				}
				qq = 0;
				if (p == 0)
					chdir("admin");
				else
					chdir(info[p].user);
				Duration = GetTickCount() - Start;
				if ((Duration < MAX_TIME))
					goto S;
				else
					break;
			}
			else if (strcmp(cp, "passwd") == 0)
			{
				if (info[p].level == 1)
				{
					for (int e = 0; e <= n; e++)
					{
						while (order[s] != '\n')
						{
							cc[d] = order[s];
							d++;
							s++;
						}
						s = s - d;
						d = 0;
						if (e == 0)
							cc[d] = '\n';
						if (strcmp(cc, info[e].user) == 0)
						{
							int pow = 0;
							printf("Enter new pass:\n");
							fgets(p1, 40, stdin);
							for (i = 0; p1[i] != NULL; i++)
							{
								in[i] = p1[i] - '0';
								if ((p1[i]) >= 'a' && (p1[i]) <= 'z')
									pow = pow + 2;
								else if ((p1[i]) >= 'A' && (p1[i]) <= 'Z')
									pow = pow + 4;
								else if ((p1[i]) >= '0' && (p1[i]) <= '9')
									pow = pow + 3;
								else if (p1[i] == ' ')
									pow = pow + 1;
								else
									pow = pow + 8;
							}
							pow = pow - 8;
							if (pow <= 33)
							{
								if (strcmp("admin\n", info[e].user) == 0)
									printf("admin's new pass is weak.");
								else
									printf("%s's new pass is weak.", info[e].user);
								Duration = GetTickCount() - Start;
								if ((Duration < MAX_TIME))
									goto S;
								else
									break;
							}
							if (pow >= 100)
							{
								pow = 100;
							}
							strcpy(info[e].pass, p1);
							if (e == p)
								strcpy(pa, p1);
							info[e].power = pow;
							getcwd(str, 200);
							int cv = qq;
							while (qq >= 0)
							{
								chdir("..");
								qq--;
							}
							qq = cv;
							if (p == 0)
								chdir("admin");
							else
								chdir(info[e].user);
							if (e == 0)
							{
								ptr = fopen("admin.txt", "w");
								fprintf(ptr, "%s %s %s %d %d %d", info[e].user, info[e].name, info[e].pass, info[e].level, info[e].power, info[e].wrong);
								fclose(ptr);
							}
							else
							{
								ptr = fopen(info[e].user, "w");
								fprintf(ptr, "%s %s %s %d %d %d", info[e].user, info[e].name, info[e].pass, info[e].level, info[e].power, info[e].wrong);
								fclose(ptr);
							}
							chdir(str);
							Duration = GetTickCount() - Start;
							if ((Duration < MAX_TIME))
								goto S;
							else
								break;
						}
					}
				}
				else
				{
					int pow = 0;
					printf("Enter new pass:\n");
					fgets(p1, 40, stdin);
					for (i = 0; p1[i] != NULL; i++)
					{
						in[i] = p1[i] - '0';
						if ((p1[i]) >= 'a' && (p1[i]) <= 'z')
							pow = pow + 2;
						else if ((p1[i]) >= 'A' && (p1[i]) <= 'Z')
							pow = pow + 4;
						else if ((p1[i]) >= '0' && (p1[i]) <= '9')
							pow = pow + 3;
						else if (p1[i] == ' ')
							pow = pow + 1;
						else
							pow = pow + 8;
					}
					pow = pow - 8;
					if (pow <= 33)
					{
						printf("your new pass is weak.");
						Duration = GetTickCount() - Start;
						if ((Duration < MAX_TIME))
							goto S;
						else
							break;
					}
					if (pow >= 100)
					{
						pow = 100;
					}
					strcpy(info[p].pass, p1);
					strcpy(pa, p1);
					info[p].power = pow;
					getcwd(str, 200);
					int cv = qq;
					while (qq >= 0)
					{
						chdir("..");
						qq--;
					}
					qq = cv;
					chdir(info[p].user);
					if (p == 0)
					{
						ptr = fopen("admin.txt", "w");
						fprintf(ptr, "%s %s %s %d %d %d", info[p].user, info[p].name, info[p].pass, info[p].level, info[p].power, info[p].wrong);
						fclose(ptr);
					}
					else
					{
						ptr = fopen(info[p].user, "w");
						fprintf(ptr, "%s %s %s %d %d %d", info[p].user, info[p].name, info[p].pass, info[p].level, info[p].power, info[p].wrong);
						fclose(ptr);
					}
					chdir(str);
					Duration = GetTickCount() - Start;
					if ((Duration < MAX_TIME))
						goto S;
					else
						break;
				}
				Duration = GetTickCount() - Start;
				if ((Duration < MAX_TIME))
					goto S;
				else
					break;
			}
			else if (strcmp(cp, "passwd-l") == 0)
			{
				if (info[p].level == 1)
				{
					while (order[s] != '\n')
					{
						cc[d] = order[s];
						d++;
						s++;
					}
					time = 0;
					for (int m = 0; cc[m] != NULL && d>0; m++, d--)
					{
						t[m] = cc[m] - '0';
						time = t[m] + time * 10;
					}
					Duration = GetTickCount() - Start;
					MAX_TIME = time + Duration;
				}
				Duration = GetTickCount() - Start;
				if ((Duration < MAX_TIME))
					goto S;
				else
					break;
			}
			else if (strcmp(cp, "chgr") == 0)
			{
				if (info[p].level == 1)
				{
					for (int e = 0; e <= n; e++)
					{
						while (order[s] != '\n')
						{
							cc[d] = order[s];
							d++;
							s++;
						}
						s = s - d;
						d = 0;
						if (e == 0)
							cc[d] = '\n';
						if (strcmp(cc, info[e].user) == 0)
						{
							if (info[e].level == 0 && info[e].power > 75 && info[e].wrong <= 10)
							{
								info[e].level = 1;
								printf("%s's level upgrade!", info[e].user);
								getcwd(str, 200);
								int cv = qq;
								while (qq >= 0)
								{
									chdir("..");
									qq--;
								}
								qq = cv;
								chdir(info[e].user);
								if (e == 0)
								{
									ptr = fopen("admin.txt", "w");
									fprintf(ptr, "%s %s %s %d %d %d", info[e].user, info[e].name, info[e].pass, info[e].level, info[e].power, info[e].wrong);
									fclose(ptr);
								}
								else
								{
									ptr = fopen(info[e].user, "w");
									fprintf(ptr, "%s %s %s %d %d %d", info[e].user, info[e].name, info[e].pass, info[e].level, info[e].power, info[e].wrong);
									fclose(ptr);
								}
								chdir(str);
							}
							else
								printf("%s can't be upgraded.", info[e].user);
							e = n + 1;
						}

					}
				}
				Duration = GetTickCount() - Start;
				if ((Duration < MAX_TIME))
					goto S;
				else
					break;
			}
			else if (strcmp(cp, "mkdir") == 0)
			{
				while (order[s] != '\n')
				{
					cc[d] = order[s];
					d++;
					s++;
				}
				mkdir(cc);
				Duration = GetTickCount() - Start;
				if ((Duration < MAX_TIME))
					goto S;
				else
					break;
			}
			else if (strcmp(cp, "pwd\n") == 0)
			{
				getcwd(add, 200);
				printf("%s\n", add);
				Duration = GetTickCount() - Start;
				if ((Duration < MAX_TIME))
					goto S;
				else
					break;
			}
			else if (strcmp(cp, "cd") == 0)
			{
				while (order[s] != '\n')
				{
					cc[d] = order[s];
					d++;
					s++;
				}
				if (strcmp("..", cc) == 0)
				{
					if (qq > 0)
					{
						chdir("..");
						qq--;
					}
					else
						printf("you can't access.");
				}
				else
				{
					qq++;
					chdir(cc);
				}
				Duration = GetTickCount() - Start;
				if ((Duration < MAX_TIME))
					goto S;
				else
					break;
			}
			else if (strcmp(cp, "ls\n") == 0)
			{
				system("dir");
				Duration = GetTickCount() - Start;
				if ((Duration < MAX_TIME))
					goto S;
				else
					break;
			}
			else if (strcmp(cp, ">\n") == 0)
			{
				char w[200], a[200], pc[300];
				int fr;
				FILE *pt;
				fgets(w, 200, stdin);
				scanf(">");
				getchar();
				fgets(a, 200, stdin);
				for (fr = 0; w[fr] != '\n'; fr++)
					w[fr] = w[fr];
				w[fr] = '\0';
				for (fr = 0; a[fr] != '\n'; fr++)
					a[fr] = a[fr];
				a[fr] = '\0';
				if (p == 0)
				{
					if (strcmp(w, "admin") == 0)
					{
						ptr = fopen("admin.txt", "r");
						pt = fopen(a, "w");
						while (!feof(ptr))
						{
							fgets(pc, 300, ptr);
							fprintf(pt, "%s", pc);
						}
						fclose(pt);
						fclose(ptr);
					}
					else
						goto c;
				}
				else
				{
				c:ptr = fopen(w, "r");
					if (ptr != NULL)
					{
						pt = fopen(a, "w");

						while (!feof(ptr))
						{
							fgets(pc, 300, ptr);
							fprintf(pt, "%s", pc);
						}
						fclose(pt);
						fclose(ptr);
					}
					else
					{
						pt = fopen(a, "w");
						fprintf(pt, "%s", w);
						fclose(pt);
					}
				}
				Duration = GetTickCount() - Start;
				if ((Duration < MAX_TIME))
					goto S;
				else
					break;
			}
			else if (strcmp(cp, ">>\n") == 0)
			{
				char w[200], a[200], pc[300];
				int fr;
				FILE *pt;
				fgets(w, 200, stdin);
				scanf(">>");
				getchar();
				fgets(a, 200, stdin);
				for (fr = 0; w[fr] != '\n'; fr++)
					w[fr] = w[fr];
				w[fr] = '\0';
				for (fr = 0; a[fr] != '\n'; fr++)
					a[fr] = a[fr];
				a[fr] = '\0';
				if (p == 0)
				{
					if (strcmp(w, "admin") == 0)
					{
						ptr = fopen("admin.txt", "r");
						pt = fopen(a, "a");
						while (!feof(ptr))
						{
							fgets(pc, 300, ptr);
							fprintf(pt, "%s", pc);
						}
						fclose(pt);
						fclose(ptr);
					}
					else
						goto A;
				}
				else
				{
				A:ptr = fopen(w, "r");
					if (ptr != NULL)
					{
						pt = fopen(a, "a");

						while (!feof(ptr))
						{
							fgets(pc, 300, ptr);
							fprintf(pt, "%s", pc);
						}
						fclose(pt);
						fclose(ptr);
					}
					else
					{
						pt = fopen(a, "a");
						fprintf(pt, "%s", w);
						fclose(pt);
					}
				}
				Duration = GetTickCount() - Start;
				if ((Duration < MAX_TIME))
					goto S;
				else
					break;
			}
			else if (strcmp(cp, "cat") == 0)
			{
				FILE *po;
				char se[300];
				while (order[s] != '\n')
				{
					cc[d] = order[s];
					d++;
					s++;
				}
				po = fopen(cc, "r");
				if (po != NULL)
				{
					while (!feof(po))
					{
						fgets(se, 300, po);
						printf("%s", se);
					}
					fclose(po);
				}
				Duration = GetTickCount() - Start;
				if ((Duration < MAX_TIME))
					goto S;
				else
					break;
			}
			else if (strcmp(cp, "rm") == 0)
			{
				int status;
				while (order[s] != '\n')
				{
					cc[d] = order[s];
					d++;
					s++;
				}
				status = remove(cc);
				if (status != 0)
				{
					printf("file doesen't exist.Unable to delete the file\n");
				}
				Duration = GetTickCount() - Start;
				if ((Duration < MAX_TIME))
					goto S;
				else
					break;
			}
			else if (strcmp(cp, "rm-r") == 0)
			{
				int statu;
				while (order[s] != '\n')
				{
					cc[d] = order[s];
					d++;
					s++;
				}
				statu = rmdir(cc);
				if (statu != 0)
					printf("directory doesen't exist.Unable to delete the directory\n");
				Duration = GetTickCount() - Start;
				if ((Duration < MAX_TIME))
					goto S;
				else
					break;
			}
			else if (strcmp(cp, "cp\n") == 0)
			{
				char qu[300], pu[300], fn[200], fnd[200], sen[300];
				int cou;
				fgets(qu, 300, stdin);
				for (cou = 0; qu[cou] != '\n'; cou++)
					qu[cou] = qu[cou];
				qu[cou] = '\0';
				fgets(fn, 200, stdin);
				for (cou = 0; fn[cou] != '\n'; cou++)
					fn[cou] = fn[cou];
				fn[cou] = '\0';
				fgets(pu, 300, stdin);
				for (cou = 0; pu[cou] != '\n'; cou++)
					pu[cou] = pu[cou];
				pu[cou] = '\0';
				fgets(fnd, 200, stdin);
				for (cou = 0; fnd[cou] != '\n'; cou++)
					fnd[cou] = fnd[cou];
				fnd[cou] = '\0';
				FILE *ex;
				FILE *de;
				getcwd(str, 200);
				chdir(qu);
				ex = fopen(fn, "r");
				chdir(pu);
				de = fopen(fnd, "w");
				if (ex != NULL)
				{
					while (!feof(ex))
					{
						chdir(qu);
						fgets(sen, 300, ex);
						chdir(pu);
						fprintf(de, "%s", sen);
					}
					fclose(ex);
					fclose(de);
				}
				chdir(str);
				Duration = GetTickCount() - Start;
				if ((Duration < MAX_TIME))
					goto S;
				else
					break;
			}
			else if (strcmp(cp, "mv\n") == 0)
			{

				char qu[300], pu[300], fn[200], fnd[200], sen[300];
				int cou;
				fgets(qu, 300, stdin);
				for (cou = 0; qu[cou] != '\n'; cou++)
					qu[cou] = qu[cou];
				qu[cou] = '\0';
				fgets(fn, 200, stdin);
				for (cou = 0; fn[cou] != '\n'; cou++)
					fn[cou] = fn[cou];
				fn[cou] = '\0';
				fgets(pu, 300, stdin);
				for (cou = 0; pu[cou] != '\n'; cou++)
					pu[cou] = pu[cou];
				pu[cou] = '\0';
				fgets(fnd, 200, stdin);
				for (cou = 0; fnd[cou] != '\n'; cou++)
					fnd[cou] = fnd[cou];
				fnd[cou] = '\0';
				FILE *ex;
				FILE *de;
				getcwd(str, 200);
				chdir(qu);
				ex = fopen(fn, "r");
				chdir(pu);
				de = fopen(fnd, "w");
				if (ex != NULL)
				{
					while (!feof(ex))
					{
						chdir(qu);
						fgets(sen, 300, ex);
						chdir(pu);
						fprintf(de, "%s", sen);
					}
					fclose(ex);
					chdir(qu);
					remove(fn);
					fclose(de);
				}
				chdir(str);
				Duration = GetTickCount() - Start;
				if ((Duration < MAX_TIME))
					goto S;
				else
					break;
			}
			else if (strcmp(cp, "exif") == 0)
			{
				while (order[s] != '\n')
				{
					cc[d] = order[s];
					d++;
					s++;
				}
				char path[100];
				struct stat stats;
				strcpy(path, cc);
				if (stat(path, &stats) == 0)
				{
					printFileProperties(stats);
					printf("\ncreator: %s\n", info[p].user);
				}
				else
				{
					printf("Unable to get file properties.\n");
					printf("Please check whether '%s' file exists.\n", path);
				}
				Duration = GetTickCount() - Start;
				if ((Duration < MAX_TIME))
					goto S;
				else
					break;
			}
			else
			{
				info[p].wrong++;
				printf("wrong order.");
				getcwd(str, 200);
				int cv = qq;
				while (qq >= 0)
				{
					chdir("..");
					qq--;
				}
				qq = cv;
				if (p == 0)
					chdir("admin");
				else
					chdir(info[p].user);
				if (p == 0)
				{
					ptr = fopen("admin.txt", "w");
					fprintf(ptr, "%s %s %s %d %d %d", info[p].user, info[p].name, info[p].pass, info[p].level, info[p].power, info[p].wrong);
					fclose(ptr);
				}
				else
				{
					ptr = fopen(info[p].user, "w");
					fprintf(ptr, "%s %s %s %d %d %d", info[p].user, info[p].name, info[p].pass, info[p].level, info[p].power, info[p].wrong);
					fclose(ptr);
				}
				chdir(str);
				Duration = GetTickCount() - Start;
				if ((Duration < MAX_TIME))
					goto S;
				else
					break;
			}
		}
			  else if (p == 99 && b != 1)
			  {
				  printf("you enter wrong information.");
			  }
		Duration = GetTickCount() - Start;
	}
	if (!(Duration < MAX_TIME))
		printf("Out of time\n");
	while (qq >= 0)
	{
		qq--;
		chdir("..");
	}
	FILE *ptr1;
	ptr1 = fopen("file1.txt", "w");
	for (int z = 0; info[z].name[0] != NULL; z++)
		fprintf(ptr1, "%s %s %s %d %d %d", info[z].user, info[z].name, info[z].pass, info[z].level, info[z].power, info[z].wrong);
	fclose(ptr1);
	return 0;
}
void printFileProperties(struct stat stats)
{
	struct tm dt;
	// File permissions
	printf("\nFile access: ");
	if (stats.st_mode)
		printf("read ");
	if (stats.st_mode)
		printf("write ");
	if (stats.st_mode)
		printf("execute");
	// File size
	printf("\nFile size: %d", stats.st_size);
	// Get file creation time in seconds and 
	// convert seconds to date and time format
	dt = *(gmtime(&stats.st_ctime));
	if ((dt.tm_min + 30) >= 60)
	{
		printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday, (dt.tm_mon + 1), dt.tm_year + 1900,
			(dt.tm_hour + 4), (dt.tm_min - 30), dt.tm_sec);
		// File modification time
		dt = *(gmtime(&stats.st_mtime));
		printf("\nModified on: %d-%d-%d %d:%d:%d", dt.tm_mday, (dt.tm_mon + 1), dt.tm_year + 1900,
			(dt.tm_hour + 4), (dt.tm_min - 30), dt.tm_sec);
	}
	else
	{
		printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday, (dt.tm_mon + 1), dt.tm_year + 1900,
			(dt.tm_hour + 3), (dt.tm_min + 30), dt.tm_sec);
		// File modification time
		dt = *(gmtime(&stats.st_mtime));
		printf("\nModified on: %d-%d-%d %d:%d:%d", dt.tm_mday, (dt.tm_mon + 1), dt.tm_year + 1900,
			(dt.tm_hour + 3), (dt.tm_min + 30), dt.tm_sec);
	}
	char xx[300];
	getcwd(xx, 300);
	printf("\nlocation: %s", xx);
}