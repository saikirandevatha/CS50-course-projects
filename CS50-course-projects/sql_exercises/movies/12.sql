select movies.title  FROM movies, stars,people  where movies.id = stars.movie_id AND people.id = stars.person_id AND  people.
name = 'Jennifer Lawrence'  AND movies.id in (select movies.id FROM movies, stars,people  where movies.id = stars.movie_id AND people
.id = stars.person_id AND people.name= 'Bradley Cooper');
