function* dateRangeGenerator(start: string, end: string, step: number) : Generator<string> {
    const startDate = new Date(start);
    const endDate = new Date(end);

    while(startDate<=endDate){
        yield startDate.toISOString().split('T')[0].trim();
        startDate.setDate(startDate.getDate()+step);
    }
};
