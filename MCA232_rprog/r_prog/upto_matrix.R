x <- 20
y <- 30

z <- x + y

a1 = c(23,12)

print(paste("Addition of two numbers is: ", z))

var = readline(prompt = "Enter a number: ")
# %% for reminde
# help("+")

a = 1:10
print(a)
help(mean)

assign("x", c(12, 34, 45, 12))

print(1/x)

sum((x-mean(x))^2)/(length(x)-1)
print(x+x)

char_arr = c('q', 'e', 'a', 'z')
char_arr

bool_arr = c(T, F, F, T, F)
bool_arr

bool_with_10 = c(0, 1, 0, 1, 1)
bool_with_10

char_arr + char_arr
str_arr = c("mango", "pineapple", "blueberry")
str_arr

combine_arr = c(char_arr, bool_arr)
combine_arr

# Accessing elements in a vector
a[length(a1)]

nums = c(34, 12, 56, -23)
length(nums)

nums[1]
nums[]
nums[length(nums)]
nums[c(2,3)] # second and third elem of num

#NA - Not available
#NAN - not a number 0/0 Inf - Inf
# <NA>

#create booleand and imaginary vectors

help("complex")

mileage = c(65311, 65624, 65908, 66219, 66499, 66821, 67145, 67447)
diff(mileage)

phone_bill = c(460, 330, 390, 370, 460, 300, 480, 320, 490, 350, 300, 480)

max(phone_bill)
sum(phone_bill)
min(phone_bill)
cumsum((phone_bill))
phone_bill[phone_bill > 400]
(length(phone_bill[phone_bill > 400])/length(phone_bill))*100


# datatypes in R
#numeric
#character
#factor - categorical dataype ? representaiton will be word, numerican or strings
#logical - 
#datae
#OSIXct
# ordered() - sorts and gives index?
help("<-")

seq1 = seq(from = 1,  by = 0.5, length = 4)
seq1

# paste function
?paste
?rep
?
  
#difference between seq and repeat
x = c(1,2,3)
rep(x, each = 3, times = 2)
?paste
  
myobj1 = seq(from=1, to=10)
myobj2 = paste(1:10)

paste()
?list
# vector of 1,2,3 repeat the vector to get eleven 1s, ten 2s, and ten 3s
ch = seq(from=1 , to=3)

studentlist = list ("MCA", "BCA", c(44,55,67,11), c(T, F, T), 51.23, 119.1)
studentlist = list(
  c("Ass-pat1", "MCQ", "Theory Test", "Practical Test"),
  matrix(c(55, 67, 96, 90, 83, 56), nrow=2),
  list(c("Stu1, Stu2, Stu3"), c(234117, 234189, 234176))
)

names(studentlist) = c("Assessments", "marks_matrix", "stud_details")
studentlist

studentlist$Assessments[4]
studentlist$marks_matrix
studentlist$stud_details



# accessing using index values
studentlist$Assessments[4]
studentlist$marks_matrix[1, c(2,3)] # 1st row 2 col, 1st row 3 col
studentlist$stud_details[[2]]
studentlist$stud_details[[2]][2]

StuVector = unlist(studentlist) # will convert list to vector
StuVector[2]

studentname = list("Michael", "John", "Steve")
coursename = list("C Programming", "Java")
college = c(studentname, coursename)
studentname[2]
college


set.seed(10) # same set of random numbers
x = c(1, 5, 4) 
sample(x, 2) # generate the sample from x
              # pick randomly 2 eles from x


?set.seed

sample(x, 10, replace = T, prob=c(1,1,1))
sample(1:50, replace=F, size=10)

#matrix creation
x = c(1,2,3,4,5,6,7,8)
mat1 = matrix(x, nrow = 4, ncol = 4, byrow = T)
# by default it is by COL
mat1

v = sample(1:50, size = 16, replace = F)
#A <- matrix(v, nrow = 4, ncol = 4)
#B <- matrix(v, nrow = 4, ncol = 4)
#C <- matrix(v, nrow = 4, ncol = 4)
#A
#B
#C
?cbind

#cbind col wise binding
# rbind - row by binding
# binds 


vect1 = c(12,34,45,56,23,1,254)
rnames <- c("row1", "row2", "row3")
cnames <- c("col1", "col2", "col3")

matrix1 = c
?matrixOps

v = sample(1:50, size = 9, replace = F)
l = sample(23:61, size = 9, replace = F)
A <- matrix(v, nrow = 3, ncol = 3)
B <- matrix(l, nrow = 3, ncol = 3)
A
B
C <- A+B
C
C <- A-B
C

A[c(T,F,T), c(F,T)]
A[c(1,3), c(F,T)]

A[c(1,2), -3]


matrix1 = matrix(v, nrow = 3, ncol = 3)
matrix1

# is for the inverse of the matrix - use solve()
solve(matrix1)

# find the determinant - using det()
det(matrix1)

?qr

# rank of matrix, mulitple returns -one of which is rank
qr(matrix1)$rank

# get diagonal of matrix
diag(matrix1)
diag(apply(matrix1, 1, rev)) # from left to right 2-> vice-versa
?apply
 
diag(matrix1) = c(10, 20, 30) # replaces the values diagonaly
#matrix1
?eigen
eigen(matrix1)


