cereal = c(
  15.5, 
  16.2,
  16.1, 
  15.8, 
  15.6, 
  16.0, 
  15.8, 
  15.9, 
  16.2
)


# alternate hypothesis
t.test(
  cereal, 
  mu = 16, 
  alternative = c("less"), 
  conf.level = 0.95, # confidence level => level of significance 1-conf.level
)

t.test(cereal) # will take only default values 


x = c(70, 82, 78, 74, 94, 82)
y = c(64, 72, 60, 76, 72, 80, 84, 68)

mean_x <- mean(x)
mean_y <- mean(y)

sd1 = sd(x)
sd2 = sd(y)

s_triangle = sqrt((sd1^2/length(x)) + (sd2^2/length(y)))

t = (mean_x - mean_y) / s_triangle
t

t = t.test(
  x,
  y,
  alternative = c("greater"),
  var.equal = TRUE
)

# take paired t test - manual way and t.test
# generate a pdf and submit
