library(ggplot2)

View(cars)

xaxis <- cars$speed # predictor
yaxis <- cars$dist # dependent

ggplot(
    data = cars,
    aes(
        x = `speed`,
        y = `dist`
    )
) + geom_point(
) + labs(
    title = 'Speed Vs. Distance',
    subtitle = 'This scatter plot shows the relation between Speed of a car & the Distance when the cars comes to a halt',
    x = 'Speed in Kilometer/Hour',
    y = 'Distance in Metre'
) + geom_smooth(
    method = 'lm',
    se = FALSE
)

# Least Square Method
Sxy = sum(
    (xaxis - mean(xaxis)) * (yaxis - mean(yaxis))
)

Sxx = sum(
    sum(xaxis - mean(xaxis))^2
)

Syy = sum(
    sum(yaxis - mean(yaxis))^2
)

beta_i_hat = Sxy/Sxx # slope
beta_0_hat = mean(yaxis) - beta_i_hat*mean(xaxis)
c(beta_0_hat, beta_i_hat)

# possible x values in cars dataset
unique(xaxis)
min(yaxis)
