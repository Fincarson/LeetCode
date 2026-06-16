function dateRangeGenerator(start: string, end: string, step: number): string[] {
    const startDate = new Date(start);
    const endDate = new Date(end);
    const datesList: string[] = [];

    while (startDate <= endDate) {
        datesList.push(formatDate(startDate));
        startDate.setDate(startDate.getDate() + step);
    }

    return datesList;
}

// Helper function to format the date
function formatDate(date: Date): string {
    const year = date.getFullYear();
    const month = String(date.getMonth() + 1).padStart(2, '0');
    const day = String(date.getDate()).padStart(2, '0');
    return `${year}-${month}-${day}`;
}
