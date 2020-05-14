input_string  = input()

ans = set([])

def solve(start,used,stri,back):
	curr_str = stri[start:]
	#print(str(start) + " ssss  " + curr_str)
	#print(used)
	if(len(curr_str)==2 or len(curr_str)==3):
		#print(back)
		if(curr_str != back[-len(curr_str):]):
			used1 = used + [curr_str]
			for st in used1:
				ans.add(st)


	if(len(curr_str)>=4):
		add_str = curr_str[0:2]
		if(add_str != back[-2:]):
			used1 = used + [add_str]
			solve(start+2,used1,stri,add_str)

	if(len(curr_str)>=5):
		add_str = curr_str[0:3]
		if(add_str != back[-3:]):
			used1 = used + [add_str]
			solve(start+3,used1,stri,add_str)


solve(0,[],input_string,'')

print(ans)