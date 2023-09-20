# ACCESS

## The virus attacked the filesystem of the supercomputer and broke the control of access rights to the files. For each file there is a known set of operations which may be applied to it:

## - write W,
## - read R,
## - execute X.

## You need to recover the control over the access rights to the files.

## Virus đã tấn công vào hệ thống tập tin của siêu máy tính và phá vỡ quyền kiểm soát truy cập vào tập tin. Với mỗi tập tin đã có một tập hợp các thao tác có thể áp dụng vào:

## - Viết W,
## - Đọc R,
## - Thực hiện X.

## Việc bạn cần làm là phải phục hồi lại quyền kiểm soát truy cập vào các tập tin này.

## Input description
## The first line contains the number N — the number of files contained in the filesystem.
## The following N lines contain the file names and allowed operations with them, separated by spaces.
## The next line contains an integer M — the number of operations to the files.
## In the last M lines specify the operations that are requested for files. One file can be requested many times.

# Constraints

## N,M<100

# Output description

## For each request your program should return OK if the requested operation is valid or Access denied if the operation is invalid.

# Sample test case

## Sample input 1
4
helloworld.exe R X
pinglog W R
nya R
goodluck X W R
5
read nya
write helloworld.exe
execute nya
read pinglog
write pinglog

## Sample output 1

OK
Access denied
Access denied
OK
OK

## test case

1 
helloworld.exe R X