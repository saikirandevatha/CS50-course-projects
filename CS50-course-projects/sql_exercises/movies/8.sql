select people.name from stars JOIN people on stars.person_id = people.id where stars.movie_id in (select id from movies where title
='Toy Story');


