#include <stdio.h>
#include <string.h>

struct Video
{
  char title[1001];
  char artist[1001];
  long long int view;
};

void swap(Video *a, Video *b)
{
  Video temp = *a;
  *a = *b;
  *b = temp;
}

void bubleSort(Video arr[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j].view < arr[j + 1].view || (arr[j].view == arr[j + 1].view && strcmp(arr[j].title, arr[j + 1].title) > 0))
      {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

int main()
{
  FILE *f = fopen("testdata.in", "r");
  Video video[100];
  int index = 0;
  while (!feof(f))
  {
    fscanf(f, "%[^#]#%[^#]#%lld\n", video[index].title, video[index].artist, &video[index].view);
    index++;
  }
  bubleSort(video, index + 1);

  for (int i = 0; i < index; i++)
  {
    printf("%s by %s - %lld\n", video[i].title, video[i].artist, video[i].view);
  }

  return 0;
}