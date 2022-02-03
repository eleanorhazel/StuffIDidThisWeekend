package quickSort;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.*;
import java.util.concurrent.ThreadLocalRandom;

import javax.swing.*;
import java.awt.*;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;




class Vars {
	public static int arrSize = 20;
	public static int[] lines = new int[arrSize+1];
}

class QuickSort
{
static int partition(int[] arr, int start, int end)
{
    int pivot = arr[end];
    int i = (start - 1);
    for (int j = start; j < end; j++)
    {
    if (arr[j] <= pivot)
    {
        i++;
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    }
		int tmp = arr[i+1];
		arr[i+1] = arr[end];
		arr[end] = tmp;

		
		return (i+1);
		
  }
  
	static void quickSort(int[] arr, int start, int end)
	{
		if (start < end)
		{
			int pIndex = partition(arr, start, end);

			quickSort(arr, start, pIndex - 1);
			quickSort(arr, pIndex + 1, end);
		}
	}
}

class SetupLines
{
	static void makeLines(int[] arr)
	{
		for (int i = 0; i < arr.length; i++)
		{
			arr[i] = i;
		}
	}

	static void randomizeArr(int[] arr)
	{
		shuffleArray(arr);
	}

	static void shuffleArray(int[] arr)
  {
    Random rnd = ThreadLocalRandom.current();
    for (int i = arr.length - 1; i > 0; i--)
    {
      int index = rnd.nextInt(i + 1);

      int a = arr[index];
      arr[index] = arr[i];
      arr[i] = a;
    }
  }
}

class SortVisualiser extends JFrame
{

	public SortVisualiser(Graphics g)
	{
			Graphics2D graphics = (Graphics2D)g;
			JFrame window = new JFrame("Visualiser");
			window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			window.setSize(1280, 720);
			window.setVisible(true);
			for (int i = 0; i< Vars.lines.length; i++)
			{
				graphics.fillRect(0, i*3, 1, i*3);
			}

	}
	
}

class Main
{
  public static void main(String args[]) {

		SetupLines.makeLines(Vars.lines);
		SetupLines.randomizeArr(Vars.lines);

		for (int i = 0; i < Vars.lines.length; i++) 
		{
			System.out.println(Vars.lines[i]);
		}

		System.out.println("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

		QuickSort.quickSort(Vars.lines, 0, Vars.lines.length -1);

		for (int i = 0; i < Vars.lines.length; i++) 
		{
			System.out.println(Vars.lines[i]);
		}

		new SortVisualiser(null);

  }
}