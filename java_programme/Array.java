package com.sridhwork;

import java.util.Scanner;

public class Array {
    private int maxSize;
    private int [] array;
    private int freeSpace;
    private  int lastIndex=0;
    public Array(int arraySize) {
        System.out.println("Creating array....");
        maxSize = arraySize;
        array = new int[arraySize];
    }

    public void viewArray(){
        System.out.print("[");
        for (int j : this.array) {
            System.out.print(j + ",");
        }
        System.out.print("]\n");
    }

    public  void insertValue(int elements){
        Scanner sc = new Scanner(System.in);
        if (elements<=this.maxSize){
            for (int i =0; i<elements;i++){
                System.out.printf("Enter the value of item %d: ", i+1);
                array[i]= sc.nextInt();
            }
            this.checkZV();
        }else {
            this.extendArray(elements);
            this.insertValue(elements);
        }
    }

    public  void insertValue(int elements, int index){
        Scanner sc = new Scanner(System.in);
        if (elements<=this.maxSize && elements+index<=this.maxSize){
            for (int i =index; i<index+elements;i++){
                System.out.printf("Enter the value of item at index %d: ", i);
                array[i]= sc.nextInt();
            }
            this.checkZV();
        }else {
            int extraSpaceRequired = (index+elements)-this.maxSize;
            this.extendArray(this.maxSize+extraSpaceRequired);
            this.insertValue(elements,index);
        }
    }

    public  void insertValue(int [] elements, int index){
        if (elements.length<=this.maxSize && elements.length+index<=this.maxSize){
            int j = 0;
            for (int i =index; i<index+elements.length;i++){
                array[i] = elements[j];
                j++;
            }
            this.checkZV();
        }else {
            int extraSpaceRequired = (index+elements.length)-this.maxSize;
            this.extendArray(this.maxSize+extraSpaceRequired);
            this.insertValue(elements,index);
        }
    }

    public void addValueToIndex(int elements, int index){
        if (elements<=this.maxSize && (index+elements)-(this.freeSpace+this.lastIndex+1)<=this.freeSpace){
            Scanner sc = new Scanner(System.in);
            int [] temp = new int[elements];
            int actualIndex = index;
            for (int i = 0; i<elements; i++){
                System.out.printf("Enter the value of item at index %d: ", actualIndex);
                temp[i]= sc.nextInt();
                actualIndex++;
            }
            this.insertValue(temp,index);
        }else{
            int extraSpaceRequired = (index+elements)-(this.freeSpace+this.lastIndex+1);
            this.extendArray(this.maxSize+extraSpaceRequired);
            this.addValueToIndex(elements,index);
        }
    }

    private void checkZV(){
        int count = 0;
        this.lastIndex = 0;
        for (int i = this.maxSize-1; i>=0; i--){
            if(array[i]==0){
                count++;
            }else {
                this.lastIndex = i;
                this.freeSpace = count;
                break;
            }
        }
        this.freeSpace = count;
    }

    public void append(int value){
        if (freeSpace>=1){
            array[lastIndex+1] = value;
            this.checkZV();
        }else {
            this.extendArray(this.maxSize+1);
            this.append(value);
        }
    }

    public void append(int [] value){
        if (freeSpace>= value.length){
            for (int j : value){
                this.append(j);
            }
            this.checkZV();
        }else {
            int extraSpaceRequired = value.length-freeSpace;
            this.extendArray(this.maxSize+extraSpaceRequired);
            this.append(value);
        }
    }

    private void extendArray(int newSize){
        if (newSize>this.maxSize){
            int [] temp = new int[newSize];
            for (int i =0; i<this.array.length; i++){
                temp[i] = array[i];
            }
            this.array = temp;
            this.maxSize = temp.length;
            this.checkZV();
        }else {
            System.out.println("Invalid size");
        }
    }

    public void delete(int index){
        if (index< this.maxSize-1){
            for (int i=index;i<this.lastIndex;i++){
                this.array[i] = this.array[i+1];
            }
            this.array[this.lastIndex]=0;
            this.checkZV();
        }
    }

}
