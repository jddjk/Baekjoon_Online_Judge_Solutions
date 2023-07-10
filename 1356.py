n=input();print('NO'if all(eval('*'.join(n[:i]))-eval('*'.join(n[i:]))for i in range(1,len(n)))else'YES')
