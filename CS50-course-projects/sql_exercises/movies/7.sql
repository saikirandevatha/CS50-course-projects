select m.title,  r.rating from movies as m JOIN ratings as r ON m.id = r.movie_id where m.year='2010' order by r.rating desc, m.title asc;


-- In 7.sql, write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.
-- Your query should output a table with two columns, one for the title of each movie and one for the rating of each movie.
-- Movies that do not have ratings should not be included in the result.
