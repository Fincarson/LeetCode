declare global {
    interface Date {
        nextDay(): string;
    }
}

Date.prototype.nextDay = function() {
    const currentDate: Date = new Date(this.getTime());
    currentDate.setDate(currentDate.getDate() + 1);
    
    const year: number = currentDate.getFullYear();
    const month: string = String(currentDate.getMonth() + 1).padStart(2, '0');
    const day: string = String(currentDate.getDate()).padStart(2, '0');

    return `${year}-${month}-${day}`;
};
