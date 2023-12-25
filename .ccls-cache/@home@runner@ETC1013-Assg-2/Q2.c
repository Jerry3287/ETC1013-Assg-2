#include <stdio.h>
#include <stdlib.h>

// structure for student
struct student {
  int id;
  char name[20];
  char gender[6];
  int test1;
  int test2;
  int test3;
};

void average(struct student *table, int lines); // average prototype
void topScore(struct student *table, int lines); // highest prototype
void totalThresh(struct student *table, int lines); // totalThresh prototype

int main() {
  FILE *source;
  char ch;
  source = fopen("StudentScore.csv", "r");

  int lines = 0; // no of lines in file

  // counting no of lines in file
  while ((ch = fgetc(source)) != EOF) {
    if (ch == '\n') {
      lines++;
    }
  }
  rewind(source); // resetting file pointer to beginning of file
  struct student *table = (struct student *)malloc(lines * sizeof(struct student)); // allocating memory for table of students

  int i = 0; // index for table of students
  while (fscanf(source, "%4d, %[^,], %[^,], %2d, %2d, %2d", &table[i].id, table[i].name, table[i].gender, &table[i].test1, &table[i].test2, &table[i].test3) != EOF) 
  {
    i++;
  }

  //function call to produce answers
  average(table, lines);
  topScore(table, lines);
  totalThresh(table, lines);

  free(table);
  fclose(source);
  return 0;
}

/**
 * average - calculates average of students' score, and store into a csv file
 * @table: pointer to table of students
 * @lines: no of lines in file
 * returns: void
 */
void average(struct student *table, int lines)
{
  //create and store averages in file
  FILE *avgFile;
  avgFile = fopen("Average.csv", "w");
  fprintf(avgFile, "ID  , %-18s, Average\n", "Name");

  int avg[50] = {0}; // array to store average of each student;
  int sum = 0;
  for (int i = 0; i < lines; i++) 
  {
    sum = table[i].test1 + table[i].test2 + table[i].test3;
    avg[i] = sum / 3;
    printf("Average of %-18s (id: %d) is %d\n", table[i].name, table[i].id, avg[i]);
    fprintf(avgFile, "%d, %-18s, %d\n", table[i].id, table[i].name, avg[i]);
  }

  fclose(avgFile);
}

/**
 * topScore - finds student with the highest score
 * @table: pointer to table of students
 * @lines: no of lines in file
 * returns: void
 */
void topScore(struct student *table, int lines)
{
  int highest = 0;
  int highestIndex = 0;
  for (int i = 0; i < lines; i++)
  {
    int total = table[i].test1 + table[i].test2 + table[i].test3;
    if (total > highest)
    {
      highest = total;
      highestIndex = i;
    }
  }

  printf("\nStudent with highest total score is %s (id: %d) with total score of %d\n", table[highestIndex].name, table[highestIndex].id, highest);
}

/**
 * totalThresh - calculates students' score total that passes threshold, and store into a csv file 
 * @table: pointer to table of students
 * @lines: no of lines in file
 * returns: void
 */
void totalThresh(struct student *table, int lines)
{
  //create and store student with total score greater than threshold in file
  FILE *threshold;
  threshold = fopen("Threshold.csv", "w");
  fprintf(threshold, "ID  , %-18s, Score\n", "Name");

  //calculate total score of each student
  int thresh = 0;
  printf("\nEnter threshold score: ");
  scanf("%d", &thresh);
  printf("\nStudents with total score greater than %d:\n", thresh);
  for (int i = 0; i < lines; i++)
  {
    int total = table[i].test1 + table[i].test2 + table[i].test3;
    if (total > thresh)
    {
      printf("%-18s (id: %d), score: %d\n", table[i].name, table[i].id, total);
      fprintf(threshold, "%d, %-18s, %d\n", table[i].id, table[i].name, total);
    }
  }

  fclose(threshold);
}