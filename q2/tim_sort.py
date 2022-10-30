def insertion_sort(a):
    for i in range(1, len(a)):
        n = a[i]
        pos = i
        while pos > 0 and a[pos-1] > n:
            a[pos] = a[pos-1]
            pos -= 1
        a[pos] = n
    return a

def merge_lists(left_sublist,right_sublist):
    i,j = 0,0
    result = []
    #iterate through both left and right sublist
    while i<len(left_sublist) and j<len(right_sublist):
        #if left value is lower than right then append it to the result
        if left_sublist[i] <= right_sublist[j]:
            result.append(left_sublist[i])
            i += 1
        else:
            #if right value is lower than left then append it to the result
            result.append(right_sublist[j])
            j += 1
    #concatenate the rest of the left and right sublists
    result += left_sublist[i:]
    result += right_sublist[j:]
    #return the result
    return result

def tim_sort(input_list, k):
    return merge_sort(input_list, k)

def merge_sort(input_list, k):
    #if list contains only 1 element return it
    if len(input_list) <= 1:
        return input_list
    elif len(input_list) <= k:
        # use insertion sort
        return insertion_sort(input_list)
    else:
        #split the lists into two sublists and recursively split sublists
        midpoint = int(len(input_list)/2)
        left_sublist = merge_sort(input_list[:midpoint], k)
        right_sublist = merge_sort(input_list[midpoint:], k)
        #return the merged list using the merge_list function above
        return merge_lists(left_sublist,right_sublist)

