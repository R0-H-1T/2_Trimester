library(readxl)
library(tidyverse)
library(dplyr)
library(ggplot2)

my_dataset = mtcars

head(my_dataset$mpg)

hist (
  my_dataset$hp,
  col = "steelblue",
  main = "Histogram",
  xlab = "Horsepower",
  ylab = "Frequency"
)

boxplot (
  my_dataset$hp,
  col = "steelblue",
  main = "Distribution of horsepower",
  ylab = "Frequency",
  border = "black"
)

plot (
  my_dataset$wt,
  my_dataset$hp,
  col = 'steelblue',
  xlab = 'Weight',
  ylab = 'Horsepower',
  pch = 19
)

head(my_dataset)
mean(my_dataset$hp, na.rm = TRUE)
View(mpg)

str(mpg)

mpg %>%
  group_by (manufacturer) %>%
  sumaraise (mean(cty))

?airquality
View(airquality)
ggplot (
  airquality$Wind,
  geom = "hisrogram"
)

t.test (
  airquality$Wind,
  mu = 9
)

# reject null hypothesis

anesthesia <- read.csv("hagfish_induction.csv", header=TRUE, sep=",")

# contains two columns - concentration && induction_time
  ## concentration is a categorical var - high, low
  ## induction_time is a categorical var

ggplot (
  aes (x = concentration, y = induction_time)
) 
+ geom_boxplot ()

t.test (induction_time ~ concentration, data = dataset_using)




















  