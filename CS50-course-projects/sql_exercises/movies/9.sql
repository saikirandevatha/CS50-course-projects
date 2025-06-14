select DISTINCT(people.name) from people, movies, stars where people.id = stars.person_id AND movies.id = stars.movie_id AND movies.year='2004' ORDER BY people.birth ASC;
